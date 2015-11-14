#ifndef _MACLIB_H
#define _MACLIB_H
typedef int DataType;
#define COUNT 8
#define RANGE 20

#ifdef __cplusplus
#define __WHERE__ do{ \
	std::cout<< "[file: " << __FILE__ << "]" \
		<< "\t[func: " << __PRETTY_FUNCTION__ << "]" \
		<< "\t[line: " << __LINE__ << "]" << std::endl; \
}while(0)

#define __DIVIDING__( str ) do{ \
	std::cout<< "********************" \
		<< str \
		<< "********************\n"; \
}while(0)

#else
#define __WHERE__ do{ \
	printf("[file: %s]\t[func: %s]\t[line: %d]\n",__FILE__,__PRETTY_FUNCTION__,__LINE__); \
}while(0)

#define __DIVIDING__( str ) do{ \
	printf("********************" str "********************\n"); \
}while(0)
#endif

#endif
