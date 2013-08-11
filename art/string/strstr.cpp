/*
 * the implementation of strstr
 * 
 * KMP
 */


int strstr(const char *str, const char *substr)
{
	if(NULL==str || NULL==substr)
		return -1;

	int len = strlen(str);
	int sublen = strlen(substr);

	if(sublen > len)
		return -1;

	int temp = len - sublen;
	
	for(int i=0 ; i<temp ; ++i)
	{
		for(int j=0 ; j<sublen ; ++j)
		{
			if(str[i+j] != substr[j])
				break;
		}
		if(j ==  sublen)
			return i+1;
	}

	return -1;
}
