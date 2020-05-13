#!/bin/bash

# These tests are designed for after the error management and identity testing of the two programs.

LIMIT_ONE=12
LIMIT_TWO=700
LIMIT_THREE=5500

TEST_ONE="Easy-peasy"
TEST_TWO="Medium"
TEST_THREE="Hard"

MAX_OPS=0
MAX_ARG=0
TOTAL=0
BOLD=$(tput bold)
LIGHT_GREEN='\033[0;32m'
PURPLE='\033[0;35m'
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

CHECKER_SAYS="Checker says your operations are..."
SUCCESS="${GREEN}${BOLD}Success!${NC}"
FAIL="${RED}${BOLD}Fail!${NC}"
RESULT="${SUCCESS}"
echo "\n"
echo "<***************| Push_Swap Simple Test |***************>"

	ARG=$(sh GenRandNums5.sh)
	echo "${PURPLE}Test: ${BOLD}${TEST_ONE}$i${NC}\n"
	NUM=$(./push_swap $ARG | wc -l)
	TOTAL=$(($TOTAL+$NUM))
	if [ $NUM -gt $MAX_OPS ]
	then
		MAX_OPS=$NUM
		MAX_ARG=$ARG
	fi
	if [ $NUM -gt $LIMIT_ONE ]
	then
		RESULT=$FAIL
		echo "${FAIL}"
		echo "${RED}Your program took $NUM operations, which exceeded the limit of $LIMIT_ONE!${NC}"
		echo "${PURPLE}Here's the numbers: ${NC}"
		echo "$ARG"
		echo "\n"
		continue
	fi	
	echo "${BLUE}${BOLD}${CHECKER_SAYS}${NC}"
	RES=$(./push_swap $ARG | ./checker $ARG)
	echo "${RES}"
	echo "\n"
	echo "Number of operations: ${GREEN}${BOLD}${NUM}${NC}"
	echo "Limit of operations: ${RED}${BOLD}${LIMIT_ONE}${NC}\n"
	echo "Result: ${RESULT}"
	echo "\n"

echo "<***************| Push_Swap Moderate Test |***************>"
	
	RESULT="${SUCCESS}"
	ARG=$(sh GenRandNums100.sh)
	echo "${PURPLE}Test: ${BOLD}${TEST_TWO}$i${NC}\n"
	NUM=$(./push_swap $ARG | wc -l)
	TOTAL=$(($TOTAL+$NUM))
	if [ $NUM -gt $MAX_OPS ]
	then
		MAX_OPS=$NUM
		MAX_ARG=$ARG
	fi
	if [ $NUM -gt $LIMIT_TWO ]
	then
		RESULT=$FAIL
		echo "${FAIL}"
		echo "${RED}Your program took $NUM operations; The limit is $LIMIT_TWO!${NC}"
		echo "${PURPLE}Here's the numbers: ${NC}"
		echo "$ARG"
		echo "\n"
		continue
	fi
	echo "${BLUE}${BOLD}${CHECKER_SAYS}${NC}"
	RES=$(./push_swap $ARG | ./checker $ARG)
	echo "${RES}"
	echo "\n"
	echo "Number of operations: ${GREEN}${BOLD}${NUM}${NC}"
	echo "Limit of operations: ${RED}${BOLD}${LIMIT_TWO}${NC}\n"
	echo "Result: ${RESULT}"
	echo "\n"

echo "<***************| Push_Swap Advanced Test |***************>"

	RESULT="${SUCCESS}"
	ARG=$(sh GenRandNums500.sh)
	echo "${PURPLE}Test: ${BOLD}${TEST_THREE}$i${NC}\n"
	NUM=$(./push_swap $ARG | wc -l)
	TOTAL=$(($TOTAL+$NUM))
	if [ $NUM -gt $MAX_OPS ]
	then
		MAX_OPS=$NUM
		MAX_ARG=$ARG
	fi
	if [ $NUM -gt $LIMIT_THREE ]
	then
		RESULT=$FAIL
		echo "${FAIL}"
		echo "${RED}Your program took $NUM operations; The limit is $LIMIT_THREE!${NC}"
		echo "${PURPLE}Here's the numbers: ${NC}"
		echo "$ARG"
		echo "\n"
		continue
	fi
	echo "${BLUE}${BOLD}${CHECKER_SAYS}${NC}"
	RES=$(./push_swap $ARG | ./checker $ARG)
	echo "${RES}"
	echo "\n"
	echo "Number of operations: ${GREEN}${BOLD}${NUM}${NC}"
	echo "Limit of operations: ${RED}${BOLD}${LIMIT_THREE}${NC}\n"
	echo "Result: ${RESULT}"