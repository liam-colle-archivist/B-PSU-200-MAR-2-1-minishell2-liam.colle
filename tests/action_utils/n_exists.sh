#!/usr/bin/sh

##
## EPITECH PROJECT, 2025
## exists.sh
## File description:
## Cuddle (Actions)
##

if [ -e $1 ]
then
    exit 1
else
    exit 0
fi
