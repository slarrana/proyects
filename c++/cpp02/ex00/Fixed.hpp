#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & rhs);
		Fixed &	operator=( Fixed const & rhs);
		~Fixed(void);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int _n;
		static const int _bits = 8;
};

#endif
