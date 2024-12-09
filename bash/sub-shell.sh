#!/bin/bash

pwd
outer_var="outer"
echo $outer_var
echo $inner_var

(
    cd ..
    pwd
    inner_var="inner"
    echo $outer_var
    echo $inner_var
)

pwd
echo $outer_var
echo $inner_var
