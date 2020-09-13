# list: 160, 206, 21, 83, 19, 24, 445, 234, 725, 328: (now: done)
# tree:
## recursion: 104, 110, 543, 226, 617, 112, 437, 572, 101, 111, 404, 687, 337, 671, //337
## level traverse: 637, 513,
## order traverse: 144, 145, 94,
## BST: 669, 230, 538, 235, 236, 108, 109, 653, 530, 501, // 235
## Trie: 208, 677 // 208
# DP:
## Fibonacci: 70, 198, 213, 64
## Matrix path: 62, 303,
## 413, 343, 279, 91, 300, 646, 376, 1143, 416,
## 494, 474, 322, 518, 139, 377, 309, 714, 123, 188, 583, 72, 650
PROBLEM_NUM = 347
PROBLEM = ./
CC = g++
DB = lldb
GFLAGS = -g -W -std=c++11
FLAGS = -W -std=c++11
EXEC = ./debug/main
DEBUG = ./debug/debug
LISTNUM = 15

########## leetcode cli ###########
TAGS = -t list
TESTCASE = -t "[0, 0]"
STATE = -q DLE
DIR = /Users/xin/Documents/Leetcode

.PHONY: all

all: $(PROBLEM)
	$(CC) $(FLAGS) $< -o $(EXEC)
	$(CC) $(GFLAGS) $< -o $(DEBUG)

run: all $(EXEC)
	$(EXEC)

debug: all $(DEBUG)
	$(DB) $(DEBUG)

list:
	leetcode list $(TAGS) $(STATE) $< | tail -n $(LISTNUM)

show:
	leetcode show $(PROBLEM_NUM) -x

code:
	leetcode show $(PROBLEM_NUM) $(DIR) -gx -o -l cpp

test:
	leetcode test $(PROBLEM)

testcase:
	leetcode test $(TESTCASE) $(PROBLEM)

submit:
	leetcode submit $(PROBLEM)
