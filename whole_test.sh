#!/bin/bash

# VALG=("valgrind" "--leak-check=full" "--show-leak-kinds=all" "--error-exitcode=1" "-q")
VALG=
MAKE_FAST=("make" "-j$(nproc)")

cd ex00 && ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test00
${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test00
EXIT_STATUS=$?
if [ $EXIT_STATUS -ne 0 ]; then
    printf "%s\n" "ex00:ERROR!"
    exit 1
fi

cd ..
cd ex01 && ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test00
${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test00
EXIT_STATUS=$?
if [ $EXIT_STATUS -ne 0 ]; then
    printf "%s\n" "ex01:ERROR!"
    exit 1
fi
${MAKE_FAST[@]} re -s && ${VALG[@]} ./test01
EXIT_STATUS=$?
if [ $EXIT_STATUS -ne 0 ]; then
    printf "%s\n" "ex01:ERROR!"
    exit 1
fi
${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test01
EXIT_STATUS=$?
if [ $EXIT_STATUS -ne 0 ]; then
    printf "%s\n" "ex01:ERROR!"
    exit 1
fi

cd ..
cd ex02 && ${MAKE_FAST[@]} re -s && ${VALG[@]} ./test00
${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test00
EXIT_STATUS=$?
if [ $EXIT_STATUS -ne 0 ]; then
    printf "%s\n" "ex02:ERROR!"
    exit 1
fi
${MAKE_FAST[@]} re -s && ${VALG[@]} ./test01
EXIT_STATUS=$?
if [ $EXIT_STATUS -ne 0 ]; then
    printf "%s\n" "ex02:ERROR!"
    exit 1
fi
${MAKE_FAST[@]} re -s "DEBUG=1" && ${VALG[@]} ./test01
EXIT_STATUS=$?
if [ $EXIT_STATUS -ne 0 ]; then
    printf "%s\n" "ex02:ERROR!"
    exit 1
fi

printf "%s\n" "All Tests Passed!"
cd ..
cd ex00 && ${MAKE_FAST[@]} -s fclean
cd ..
cd ex01 && ${MAKE_FAST[@]} -s fclean
cd ..
cd ex02 && ${MAKE_FAST[@]} -s fclean
cd ..
