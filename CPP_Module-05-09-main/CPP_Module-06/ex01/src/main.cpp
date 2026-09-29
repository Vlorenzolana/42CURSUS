/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:32:58 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/18 11:32:59 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int	main()
{
    Data data;

    data.id = 42;
    data.value = 3.14;

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << ptr << std::endl;
    std::cout << "Serialized value:  " << raw << std::endl;
    std::cout << "Deserialized ptr:  " << restored << std::endl;

    std::cout << "ID: " << restored->id << std::endl;
    std::cout << "Value: " << restored->value << std::endl;

    return 0;
}