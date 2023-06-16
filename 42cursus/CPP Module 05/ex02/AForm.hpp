/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:56:04 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 16:09:08 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		AForm(void);
		AForm(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& ref);
		virtual ~AForm();

		AForm& operator=(const AForm& ref);

		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat& signer);
		virtual void		execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& ref);

#endif