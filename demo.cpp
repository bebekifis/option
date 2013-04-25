/*
 * Copyright (c) 2013, Yinan Yu (bebekifis@gmail.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * 
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * Author: Yinan Yu
 * Time: Feb/15/2013
 * Email: bebekifis@gmail.com
 * Filename: main.cpp
 * Description: 
 */
#include <vector>
#include <string>
#include "options.h"

using namespace std;

string def_opt[][2] = {
    {"eta", "1.0"},
    {"lambda","0.0"},
    {"gamma","1.0"},
    {"max-epoch","20"}, 
    {"nmodel","64"},
    {"dim","82560"},
    {"test-freq","1"},
    {"train-range","2"},
    {"save-path","./"},
    {"format", "%d.sv"},
    {"maxp", "5"},
    {"batch-size", "128"},
    {"sigma", "0.01"}};
    
int main(int argc, char ** argv)
{
    // Option initialization
    Option op = Option(sizeof(def_opt)/2/sizeof(string), def_opt);
    op.parseOption(argc, argv);
    op.print();

    return 0;
}
