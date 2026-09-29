/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:35:49 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/31 14:56:12 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP // Guarda de inclusión: evita que el archivo se incluya más de una vez
#define BUREAUCRAT_HPP // Define la macro para activar la guarda

#include <string>    // Para usar std::string
#include <iostream>  // Para usar std::ostream (operador <<)
#include <exception> // Para usar std::exception (clase base de excepciones)

class Bureaucrat // Declaración de la clase Bureaucrat
{
    private: // Sección privada: solo accesible desde dentro de la clase
        const std::string   name;  // Nombre del burócrata (constante, no se puede cambiar tras construcción)
        int                 grade; // Grado del burócrata (1 = máximo, 150 = mínimo)

    public: // Sección pública: accesible desde fuera de la clase
        Bureaucrat(const std::string& name, int grade); // Constructor parametrizado: crea un burócrata con nombre y grado
        Bureaucrat(const Bureaucrat& other);             // Constructor de copia: crea un burócrata copiando otro
        Bureaucrat& operator=(const Bureaucrat& other);  // Operador de asignación: asigna los valores de otro burócrata
        ~Bureaucrat();                                   // Destructor: se llama al destruir el objeto
    
    const std::string&  getName() const;  // Getter: devuelve el nombre del burócrata (referencia constante)
    int                 getGrade() const; // Getter: devuelve el grado del burócrata

    void    incrementGrade(); // Incrementa el grado (lo sube, es decir grade - 1)
    void    decrementGrade(); // Decrementa el grado (lo baja, es decir grade + 1)

    class GradeTooHighException : public std::exception // Excepción personalizada: grado demasiado alto (< 1)
    {
        public:
            virtual const char* what() const throw(); // Devuelve el mensaje de error de la excepción
    };

    class GradeTooLowException : public std::exception // Excepción personalizada: grado demasiado bajo (> 150)
    {
        public:
            virtual const char* what() const throw(); // Devuelve el mensaje de error de la excepción
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b); // Sobrecarga del operador << para imprimir un Bureaucrat por stream

#endif // Fin de la guarda de inclusió