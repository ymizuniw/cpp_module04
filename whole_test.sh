#!/bin/bash

UNAME=$(uname)
if [ "$UNAME" = "Linux" ]; then
    VALG=("valgrind" "--leak-check=full" "--show-leak-kinds=all" "--error-exitcode=1" "-q")
else
    VALG=()
fi

MAKE_FAST=("make" "-j$(nproc)")

run() {
    DIR=$1
    BIN=$2
    DEBUG_FLAG=$3

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

run ex00 test00
run ex01 test00
run ex01 test01
run ex02 test00
run ex02 test01

run ex00 test00 "DEBUG=1"
run ex01 test00 "DEBUG=1"
run ex01 test01 "DEBUG=1"
run ex02 test00 "DEBUG=1"
run ex02 test01 "DEBUG=1"

# cd ex00 && ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test00
# ${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test00
# EXIT_STATUS=$?
# if [ $EXIT_STATUS -ne 0 ]; then
#     printf "%s\n" "ex00:ERROR!"
#     exit 1
# fi

# cd ..
# cd ex01 && ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test00
# ${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test00
# EXIT_STATUS=$?
# if [ $EXIT_STATUS -ne 0 ]; then
#     printf "%s\n" "ex01:ERROR!"
#     exit 1
# fi
# ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test01
# EXIT_STATUS=$?
# if [ $EXIT_STATUS -ne 0 ]; then
#     printf "%s\n" "ex01:ERROR!"
#     exit 1
# fi
# ${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test01
# EXIT_STATUS=$?
# if [ $EXIT_STATUS -ne 0 ]; then
#     printf "%s\n" "ex01:ERROR!"
#     exit 1
# fi

# cd ..
# cd ex02 && ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test00
# ${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test00
# EXIT_STATUS=$?
# if [ $EXIT_STATUS -ne 0 ]; then
#     printf "%s\n" "ex02:ERROR!"
#     exit 1
# fi
# ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test01
# EXIT_STATUS=$?
# if [ $EXIT_STATUS -ne 0 ]; then
#     printf "%s\n" "ex02:ERROR!"
#     exit 1
# fi
# ${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test01
# EXIT_STATUS=$?
# if [ $EXIT_STATUS -ne 0 ]; then
#     printf "%s\n" "ex02:ERROR!"
#     exit 1
# fi

printf "%s\n" "All Tests Passed!"
cd ex00 && ${MAKE_FAST[@]} -s fclean
cd ..
cd ex01 && ${MAKE_FAST[@]} -s fclean
cd ..
cd ex02 && ${MAKE_FAST[@]} -s fclean
cd ..
