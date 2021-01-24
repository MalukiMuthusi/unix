#!/bin/bash

cc -o client.o -std=c99 -D_XOPEN_SOURCE=600 -D_DEFAULT_SOURCE -Wno-unused-parameter -Wimplicit-fallthrough -Wno-sign-compare -Wmissing-prototypes -Wall -W -pedantic greatings_client.c
