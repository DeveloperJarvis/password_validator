// --------------------------------------------------
// -*- C -*- Compatibility Header
//
// Copyright (C) 2023 Developer Jarvis (Pen Name)
//
// This file is part of the [Project Name] Library. This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// password_validator - Check if a password contains: uppercase, lowercase, digits, special characters
//						Concepts: string scanning, character classification
//
// Author: Developer Jarvis (Pen Name)
// Contact: https://github.com/DeveloperJarvis
//
// --------------------------------------------------

#include <stdio.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

// function declaration/ prototype
void display_help(char *arg);
void display_version(char *arg);
void password_validator(char *arg);
int string_length(char *arg);

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("No arguments provided.\n");
		display_help(argv[0]);
		return 0;
	}
	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
		display_help(argv[0]);
	else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
		display_version(argv[0]);
	else
		password_validator(argv[1]);
}

void display_help(char *arg)
{
	printf("Usage: %s <password_string>\n", arg);
	printf(" -h --help		display help\n");
	printf(" -v --version		display version\n");
}

void display_version(char *arg)
{
	printf("%s version: 1.0.0\n", arg);
}

void password_validator(char *arg)
{
	int length = string_length(arg);
	int isUpper = 0, isLower = 0, isNumber = 0, isSpChar = 0;
	if (length == 0)
		printf("Invalid password\n");
	else if (length > MAX_LENGTH)
		printf("Password is too long. Max length allowed: %d\n", MAX_LENGTH);
	else if (length < MIN_LENGTH)
		printf("Password is too short. Min length allowed: %d\n", MIN_LENGTH);
	else
	{
		for (int i = 0; i < length; i++)
		{
			int c = (unsigned char)arg[i];
			// have upper case
			if (c >= 'A' && c <= 'Z')
				isUpper = 1;
			// have lower case
			else if (c >= 'a' && c <= 'z')
				isLower = 1;
			// have number
			else if (c >= '0' && c <= '9')
				isNumber = 1;
			// have special case character
			else if (c > 32 && c < 127)
				isSpChar = 1;
			else
			{
				printf("Invalid characters are available in password\n");
				return;
			}
		}
		if (isUpper && isLower && isNumber && isSpChar)
			printf("Valid password\n");
		else
		{
			if (!isUpper)
				printf("Password should have atlease 1 upper case alphabet\n");
			if (!isLower)
				printf("Password should have atlease 1 lower case alphabet\n");
			if (!isNumber)
				printf("Password should have atlease 1 number\n");
			if (!isSpChar)
				printf("Password should have atlease 1 special character\n");
		}
	}
	return;
}

int string_length(char *arg)
{
	int len = 0;
	for (int i = 0; arg[i] != '\0'; i++)
		len++;
	return len;
}
