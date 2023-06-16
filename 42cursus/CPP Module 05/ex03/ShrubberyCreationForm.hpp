/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:22:51 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:27:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <string>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string name, bool isSigned);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);

		void					execute(Bureaucrat const& executor) const;
};

#endif