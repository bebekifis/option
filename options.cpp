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
 * Filename: options.cpp
 * Description:
 */
#include <stdlib.h>
#include "options.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

Option::Option()
{
    
}

Option::~Option()
{

}

void Option::parseOption(int argc, char ** argv)
{
    for (int i = 1; i < argc; i++)
    {
        char * str = argv[i];
        if (!(str[0] == '-' && str[1] == '-'))
        {
            fprintf(stderr, "error: option format incorrect\n");
            usage(argv[0]);
            exit(-1);
        }

        str+=2;
        string bak = string(argv[i]);
        const char * p = strtok(str, "=");
        string key = string(p ? p : "");
        p = strtok(NULL, "");
        string val = string(p ? p : "");
        if (opt.find(key) == opt.end() || val.empty())
        {
            fprintf(stderr, "error: unknow option %s\n", bak.c_str());
            usage(argv[0]);
            exit(-1);
        }
        else
        {
            opt[key] = val;
        }
    }
}

void Option::regist(string key, string val)
{
    assert(!key.empty());
    assert(!val.empty());
    opt[key] = val;
}

void Option::print()
{
    fprintf(stderr, "options:\n");
    for (map<string,string>::iterator it = opt.begin(); it != opt.end();it++)
    {
        fprintf(stderr, "%s:\t%s\n", it->first.c_str(), it->second.c_str());
    }
}

void Option::usage(char * exename)
{
    fprintf(stderr, "Usage: %s --key=val\n", exename);
}
