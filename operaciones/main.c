#include "my_io.h"
#include "arithmetic.h"
#include "conversion.h"

int main() {
    // Variables para operaciones binarias y hexadecimales
    char bin1[33], bin2[33], hex1[9], hex2[9];
    int num1_bin, num2_bin, num1_hex, num2_hex;
    int sum_bin, diff_bin, prod_bin, quot_bin;
    int sum_hex, diff_hex, prod_hex, quot_hex;
	char bin_result[33], hex_result[9];
    // Entrada y operaciones para números binarios
    my_printf("Enter two binary numbers (format: bin1 bin2):\n");
    my_scanf("%s %s", bin1, bin2);

    num1_bin = bin_to_int(bin1);
    num2_bin = bin_to_int(bin2);

    sum_bin = add(num1_bin, num2_bin);
    diff_bin = subtract(num1_bin, num2_bin);
    prod_bin = multiply(num1_bin, num2_bin);
    quot_bin = divide(num1_bin, num2_bin);

    my_printf("Results for binary operations:\n");
    my_printf("Sum: %b\n", int_to_str(sum_bin, bin_result, 2));
    my_printf("Difference: %b\n", int_to_str(diff_bin,bin_result, 2));
    my_printf("Product: %b\n", int_to_str(prod_bin, bin_result, 2));
    my_printf("Quotient: %b\n", int_to_str(quot_bin, bin_result, 2));

    // Entrada y operaciones para números hexadecimales
    my_printf("Enter two hexadecimal numbers (format: hex1 hex2):\n");
    my_scanf("%s %s", hex1, hex2);

    num1_hex = hex_to_int(hex1);
    num2_hex = hex_to_int(hex2);

    sum_hex = add(num1_hex, num2_hex);
    diff_hex = subtract(num1_hex, num2_hex);
    prod_hex = multiply(num1_hex, num2_hex);
    quot_hex = divide(num1_hex, num2_hex);

    my_printf("Results for hexadecimal operations:\n");
    my_printf("Sum: %x\n", int_to_str(sum_hex, hex_result, 16));
    my_printf("Difference: %x\n", int_to_str(diff_hex, hex_result, 16));
    my_printf("Product: %x\n", int_to_str(prod_hex, hex_result, 16));
    my_printf("Quotient: %x\n", int_to_str(quot_hex, hex_result, 16));

    return 0;
}

