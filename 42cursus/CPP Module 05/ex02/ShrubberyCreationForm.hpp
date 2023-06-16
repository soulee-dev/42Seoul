/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:22:51 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 14:54:50 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string name, bool isSigned);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);

		void					beSigned(const Bureaucrat& signer);
		void					execute(Bureaucrat const& executor);
};

#endif