/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:28:46 by soulee            #+#    #+#             */
/*   Updated: 2023/06/16 17:00:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string name, bool isSigned);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);

		void					execute(Bureaucrat const& executor) const;
};

#endif