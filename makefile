#!/bin/bash

default: all

all: create_directory classic_assert thd_assert

create_directory:
	@if [ ! -d "bin" ]; then mkdir bin; fi

classic_assert:
	gcc -o bin/main_classic_assert src/main_classic_assert.c

thd_assert:
	gcc -o bin/main_thd_assert src/main_thd_assert.c

clean:
	rm -rf bin
