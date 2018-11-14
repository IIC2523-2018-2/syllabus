#!/bin/bash

cp $1 $2

ab -n $1 -c $2 https://p7v0tjqgrk.execute-api.us-east-1.amazonaws.com/dev/
ab -n $1 -c $2 http://localhost:3000/
