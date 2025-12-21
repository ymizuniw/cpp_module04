#!/bin/bash

# set -o errexit  # エラー時にスクリプトを終了する
set -o nounset  # 未定義の変数を参照したらエラー出して終了する
set -o pipefail # 最後のエラーステータスを返す
# set -o xtrace   # 実行するコマンドを逐一表示する

UNAME=$(uname)
if [ "$UNAME" = "Linux" ]; then
    VALG=("valgrind" "--leak-check=full" "--show-leak-kinds=all" "--error-exitcode=1")
else
    VALG=(true)
fi

MAKE_FAST=("make" "-j$(nproc)")

run() {
    DIR=$1
    BIN=$2
    DEBUG_FLAG=${3:-}
    
    cd "$DIR" || exit 1
    ${MAKE_FAST[@]} re -s $DEBUG_FLAG && ${VALG[@]} "./$BIN" >test.log 2>&1
    EXIT_STATUS=$?
    cd ..
    
    if [ $EXIT_STATUS -ne 0 ]; then
        printf "%s\n" "$DIR:$BIN ERROR!"
        exit 1
    else
        printf "%s\n" "$DIR:$BIN SUCCESS!"
    fi
}

echo "
=====run normal test=====
"
run ex00 test00
run ex01 test00
run ex01 test01
run ex02 test00
run ex02 test01

echo "
=====run DEBUG=1 test=====
"
run ex00 test00 "DEBUG=1"
run ex01 test00 "DEBUG=1"
run ex01 test01 "DEBUG=1"
run ex02 test00 "DEBUG=1"
run ex02 test01 "DEBUG=1"

printf "\n%s\n" "=====All Tests Passed!====="
cd ex00 && ${MAKE_FAST[@]} -s fclean
cd ..
cd ex01 && ${MAKE_FAST[@]} -s fclean
cd ..
cd ex02 && ${MAKE_FAST[@]} -s fclean
cd ..
