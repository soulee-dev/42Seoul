/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:51:29 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:26:37 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();

		Bureaucrat&	operator=(const Bureaucrat& ref);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);
		void				increaseGrade(void);
		void				decreaseGrade(void);
		void				signForm(Form& form);
		void				executeForm(Form const& form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref);

#endif