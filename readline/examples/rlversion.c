/*
 * rlversion -- print out readline's version number
 */

/* Copyright (C) 1987-2009 Free Software Foundation, Inc.

   This file is part of the GNU Readline Library (Readline), a library for
   reading lines of text with interactive input and history editing.

   Readline is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Readline is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Readline.  If not, see <http://www.gnu.org/licenses/>.
*/

// g++ rlversion.c -lreadline -o 123
#include <stdio.h>
#include <sys/types.h>

#  include <stdlib.h>
#  include <readline/readline.h>


int main()
{
	printf ("%s\n", rl_library_version ? rl_library_version : "unknown");
	exit (0);
	return 0;
}











