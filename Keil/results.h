unsigned long return_7aga(int num_digits)   
{
		unsigned long result = 1;
		int i;
		for(i = 0;i<num_digits-1;i++)
		{
				result = result*10;
		}
		return result;
}


void print_result(unsigned long res)
{
		if(res)
		{
				
				int num_digits = 0;
				unsigned long temp = res;
				while (temp > 0) 
				{
						num_digits++;
						temp /= 10;
				}
				while (num_digits >0) 
				{
						unsigned long y = return_7aga(num_digits);
						char z = ((res / y) + '0');
						write_data(z);
						res %= y;
						num_digits--;		
				}
		}
		else{
				write_data('0');
		}
}