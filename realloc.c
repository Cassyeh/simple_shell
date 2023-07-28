#include "shell.h"

/**
* _memcpy - copy infos between void ptrs
* @newptr: destination ptr
* @ptr: the source pointer
* @size: the size of the new ptr
* Return: 0
*/

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_newptr = (char *)newptr;
	char *char_ptr = (char *)ptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
* _realloc - reallocates a memory block
* @ptr: pointer to the memory prev allocated
* @old_size: size in bytes of the allocated space of pointer
* @new_size: new size in bytes of the new memory block
* Return: pointer
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}
