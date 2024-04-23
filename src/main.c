/**
 * Copyright (C) 2024 Xiang-Guan Deng Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------------------
 *
 * \file     main.c
 * \brief    Wrap malloc, free functions. Develop and manage status of allocation.
 * \version  v1.0.0
 * \date     23. April. 2023
 *
 * \author   Xiang-Guan Deng
 *
 * -----------------------------------------------------------------------------
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void *__real_malloc(size_t sz);
extern void __real_free(void *p);

void *__wrap_malloc(size_t sz)
{
	printf("Wrap malloc\n");
	// TODO, manage malloc
	
	return __real_malloc(sz);
}

void __wrap_free(void *p)
{
	printf("Wrap free\n");
	// TODO, manage free
	
	__real_free(p);
}


int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	int *data = (int *)malloc(100);
	memset(data, 0xA5, 100);
	free(data);

	return 0;
}
