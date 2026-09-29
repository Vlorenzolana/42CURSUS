/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:44:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/04/02 16:46:07 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Creating a Bureaucrat ===" << std::endl;
    Bureaucrat boss("Boss", 45); // Crea un burocrata llamado "Boss" con grado 45 (rango valido: 1-150)
    std::cout << boss << std::endl; // Imprime: "Boss, bureaucrat grade 45."

    std::cout << "\n=== Creating a Form ===" << std::endl;

    //PresidentialPardonForm form("Arthur Dent"); // Formulario de perdon presidencial (grados: 25/5)
    ShrubberyCreationForm form("home"); // Crea formulario de arbustos con target "home" (grados: 145/137)
    //RobotomyRequestForm form("Bender"); // Formulario de robotomia (grados: 72/45), 50% de exito

    std::cout << form << std::endl; // Imprime nombre, si esta firmado, y grados requeridos

    std::cout << "\n=== Trying to execute WITHOUT signing ===" << std::endl;
    try
    {
        boss.executeForm(form); // Intenta ejecutar sin firmar -> lanza excepcion "form not signed"
    }
    catch (std::exception& e) // Captura la excepcion lanzada por executeForm
    {
        std::cout << "Exception: " << e.what() << std::endl; // Imprime el mensaje de error
    }

    std::cout << "\n=== Signing the form ===" << std::endl;
    boss.signForm(form); // Boss (grado 45) firma el formulario (requiere 145) -> exito, 45 < 145

    std::cout << "\n=== Executing the form ===" << std::endl;
    boss.executeForm(form); // Boss (grado 45) ejecuta el formulario (requiere 137) -> exito, crea archivo "home_shrubbery"

    std::cout << "\n=== Final state ===" << std::endl;
    std::cout << form << std::endl; // Imprime el formulario, ahora con signed: true

    return 0;
}