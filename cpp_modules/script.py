def generate_class_files(class_name, attributes):
    # Crear el archivo .hpp
    hpp_content = "#ifndef " + class_name.upper() + "_HPP\n"
    hpp_content += "#define " + class_name.upper() + "_HPP\n\n"
    hpp_content += '#include <string>\n'
    hpp_content += '#include <iostream>\n'
    hpp_content += '#include <iomanip>\n\n'
    hpp_content += 'class ' + class_name + '\n'
    hpp_content += '{\npublic:\n'
    
    # Constructor
    hpp_content += '\t' + class_name + '();\n'

    # Getters y Setters
    for attribute in attributes:
        hpp_content += '\t' + attribute["type"] + ' get_' + attribute["name"] + '() const;\n'
        hpp_content += '\tvoid set_' + attribute["name"] + '(' + attribute["type"] + ' ' + attribute["name"] + ');\n'

    hpp_content += 'private:\n'
    # Atributos
    for attribute in attributes:
        hpp_content += '\t' + attribute["type"] + ' ' + attribute["name"] + ';\n'
    
    hpp_content += '};\n\n'
    hpp_content += "#endif // " + class_name.upper() + "_HPP\n"

    # Escribir en el archivo .hpp
    with open(class_name + '.hpp', 'w') as hpp_file:
        hpp_file.write(hpp_content)

    # Crear el archivo .cpp
    cpp_content = '#include "' + class_name + '.hpp"\n\n'
    cpp_content += class_name + '::' + class_name + '()\n'
    cpp_content += '{\n'
    # Inicializar atributos en el constructor si es necesario
    for attribute in attributes:
        cpp_content += '\t// Inicializar ' + attribute["name"] + ' si es necesario\n'
    cpp_content += '}\n\n'

    # Implementar los getters y setters
    for attribute in attributes:
        cpp_content += attribute["type"] + ' ' + class_name + '::get_' + attribute["name"] + '() const\n'
        cpp_content += '{\n'
        cpp_content += '\treturn ' + attribute["name"] + ';\n'
        cpp_content += '}\n\n'
        
        cpp_content += 'void ' + class_name + '::set_' + attribute["name"] + '(' + attribute["type"] + ' ' + attribute["name"] + ')\n'
        cpp_content += '{\n'
        cpp_content += '\tthis->' + attribute["name"] + ' = ' + attribute["name"] + ';\n'
        cpp_content += '}\n\n'

    # Escribir en el archivo .cpp
    with open(class_name + '.cpp', 'w') as cpp_file:
        cpp_file.write(cpp_content)

# Ejemplo de uso
class_name = input("Ingrese el nombre de la clase: ")
attributes = []
while True:
    attribute_name = input("Ingrese el nombre del atributo (o 'fin' para terminar): ")
    if attribute_name.lower() == 'fin':
        break
    attribute_type = input("Ingrese el tipo del atributo: ")
    attributes.append({"name": attribute_name, "type": attribute_type})

generate_class_files(class_name, attributes)
