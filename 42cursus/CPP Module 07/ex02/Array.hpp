/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:14:52 by soulee            #+#    #+#             */
/*   Updated: 2023/06/25 15:27:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		std::size_t	_size;
		T			*arr;
	public:
		Array(void) : _size(0)
		{
			std::cout << "[Array] Default constructor" << std::endl;
			this->arr = new T[this->_size];
		}
		Array(size_t n) : _size(n)
		{
			std::cout << "[Array] Parameterized constructor" << std::endl;
			this->arr = new T[this->_size];
		}
		Array(const Array& ref)
		{
			std::cout << "[Array] Copy constructor" << std::endl;
			this->arr = NULL;
			*this = ref;
		}
		~Array()
		{
			std::cout << "[Array] Destructor" << std::endl;
			if (this->arr)
				delete[] this->arr;
		}

		Array&		operator=(const Array& ref)
		{
			if (this->arr)
				delete[] this->arr;
			if (ref.size() > 0)
			{
				this->_size = ref.size();
				this->arr = new T[this->_size];
				for (std::size_t i = 0; i < this->_size; i++)
					this->arr[i] = ref.arr[i];
			}
			return (*this);
		}

		std::size_t	size(void) const
		{
			return (this->_size);
		}
		T&			operator[](std::size_t i)
		{
			if (i >= this->_size || !this->arr)
				throw Array::OutOfRangeException();
			return (this->arr[i]);
		}
		const T&	operator[](std::size_t i) const
		{
			if (i >= this->_size || !this->arr)
				throw Array::OutOfRangeException();
			return (this->arr[i]);
		}

		class	OutOfRangeException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

template <typename T>
const char*	Array<T>::OutOfRangeException::what() const throw()
{
	return ("Out Of Range");
}

#endif