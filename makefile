#!/bin/bash

default: all

all: classic_assert thd_assert

classic_assert:
	gcc -o bin/main_classic_assert src/main_classic_assert.c

thd_assert:
	gcc -o bin/main_thd_assert src/main_thd_assert.c
