/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:18:30 by soulee            #+#    #+#             */
/*   Updated: 2023/06/26 22:35:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename MutantStack<T>::stack::container_type::iterator				iterator;
		typedef typename MutantStack<T>::stack::container_type::const_iterator			const_iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator		reverse_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack(void)
		{
			std::cout << "[MutantStack] Default constructor" << std::endl;
		}
		MutantStack(const MutantStack& ref)
		{
			*this = ref;
		}
		~MutantStack()
		{
			std::cout << "[MutantStack] Destructor" << std::endl;
		}

		MutantStack&	operator=(const MutantStack& ref)
		{
			*this = ref;
			return (*this);
		}

		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}

		const_iterator	cbegin(void)
		{
			return (this->c.cbegin());
		}
		const_iterator	cend(void)
		{
			return (this->c.cend());
		}

		reverse_iterator	rbegin(void)
		{
			return (this->c.regin());
		}
		reverse_iterator	rend(void)
		{
			return (this->c.rend());
		}

		const_reverse_iterator	crbegin(void)
		{
			return (this->crbegin());
		}
		const_reverse_iterator	crend(void)
		{
			return (this->crend());
		}
};

#endif