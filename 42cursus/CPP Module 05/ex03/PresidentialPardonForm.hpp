/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:16:30 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 20:26:46 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string name, bool isSigned);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);

		void					execute(Bureaucrat const& executor) const;
};

#endif