struct vector{
	int count;
	int capacity;
	void* buffer;
};

#define new(p, t)\
t *p = malloc(sizeof(t))

#define new_vector(p,t)\
{\
	(p) = malloc(sizeof(struct vector));\
	(p)->count = 0;\
	(p)->capacity = 4;\
	(p)->buffer = malloc(sizeof(t)*((p)->capacity));\
}

#define push_back(p, e, t)\
{\
	if((p)->count >= (p)->capacity){\
		(p)->capacity *= 2;\
		(p)->buffer = realloc((p)->buffer,sizeof(t)*((p)->capacity));\
	}\
	((t*)(p)->buffer)[(p)->count++] = (e);\
}
#define remove(p, e, t)\
{\
	int _i;\
	for(_i = 0;_i < (p)->count;_i++){\
		if(((t*)(p)->buffer)[_i] == (e))\
			break;\
	}\
	if(_i < (p)->count)\
		(p)->count--;\
	for(;_i < (p)->count;_i++)\
		((t*)(p)->buffer)[_i] = ((t*)(p)->buffer)[_i + 1];\
	if((p)->count < (p)->capacity/2){\
		(p)->capacity /= 2;\
		(p)->buffer = realloc((p)->buffer,sizeof(t)*((p)->capacity));\
	}\
}

#define clear_vector(p,t)\
{\
	(p)->count = 0;\
	(p)->capacity = 4;\
	(p)->buffer = realloc((p)->buffer,sizeof(t)*((p)->capacity));\
}

#define free_vector(p)\
free((p)->buffer);\
free(p);

#define get(p, i, t)	((t*)(p)->buffer)[(i)]
