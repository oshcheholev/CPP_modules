#!/bin/bash

BIN=./RPN

echo "=============================="
echo "VALID CASES"
echo "=============================="

$BIN "3 4 +"
$BIN "5 1 2 + 4 * + 3 -"
$BIN "8 9 * 9 - 9 - 9 - 4 - 1 +"
$BIN "7 2 /"
$BIN "9 1 -"
$BIN "2 3 4 + *"
$BIN "4 2 + 3 *"
$BIN "9 3 /"
$BIN "1 2 + 3 4 + *"

echo
echo "=============================="
echo "EDGE VALID CASES"
echo "=============================="

$BIN "0 1 +"
$BIN "1 0 +"
$BIN "9"
$BIN "1 1 +"
$BIN "9 9 *"

echo
echo "=============================="
echo "INVALID CASES — SYNTAX"
echo "=============================="

$BIN ""
$BIN " "
$BIN "1 +"
$BIN "+"
$BIN "1 2"
$BIN "1 2 3 +"
$BIN "1 2 + +"
$BIN "1 + +"
$BIN "1 2 + 3"

echo
echo "=============================="
echo "INVALID CASES — TOKENS"
echo "=============================="

$BIN "a b +"
$BIN "1 a +"
$BIN "1 2 &"
$BIN "1 2 ^"
$BIN "1 2 ++"
$BIN "10 2 +"
$BIN "-1 2 +"

echo
echo "=============================="
echo "INVALID CASES — DIV BY ZERO"
echo "=============================="

$BIN "1 0 /"
$BIN "9 0 /"
$BIN "0 0 /"

echo
echo "=============================="
echo "INVALID CASES — BAD SPACING"
echo "=============================="

$BIN "12+"
$BIN "1+2"
$BIN "1   2   +"
$BIN " 1 2 + "
$BIN "1,2,+"

echo
echo "=============================="
echo "DONE"
echo "=============================="
