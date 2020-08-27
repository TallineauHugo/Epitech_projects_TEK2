//
// EPITECH PROJECT, 2018
// nano
// File description:
// macro
//

#pragma once

#define BAD_PIN_FORMAT "Syntax Error: pin number must be an integer !"
#define SYNTAX_TYPE_NAME "Syntax Error: please use [type] [name] format !"
#define INVALID_TYPE "Syntax Error: invalid chipset type : \'"
#define INVALID_NAME "Syntax Error: a component name is invalid:"
#define SAME_NAME "Syntax Error: several components share the same name: "
#define MISSING_SECTION "Syntax Error: No chipset or links section !"

#define INVALID_FILE "File Error: Given file does not exist or canot be \
openned !"
#define INVALID_EXTENSION "File Error: Invalid file extension, expected .nts !"

#define UNKNOWN_INPUT "Input Error: A provided input is unknown !"
#define NOT_INPUT "Input Error: A provided input is not an Input component: "
#define INVALID_VALUE "Input Error: A provided value is invalid, must be '0' \
or '1' !"
#define UNDEFINED_INPUT "Input Error: One or several input \
values were not provided on the command line: "

#define NOT_LINKED "Link Error: One or several \
outputs are not linked : "
#define WRONG_LINK "Link Error: A requested pin can't be computed !"
#define UNKNOWN_COMP "Link Error: A linked component is unknown !"

#define UNKNOWN_PIN "Pin Error: A requested pin does not exist !"
#define UNDEFINED_PIN "Pin Error: one or several inputs are not defined !"
