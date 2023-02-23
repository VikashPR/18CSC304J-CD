# Grammar rules
rules = {
    'E': ['T', 'E\''],
    'E\'': ['+', 'T', 'E\''],
    'T': ['F', 'T\''],
    'T\'': ['*', 'F', 'T\''],
    'F': ['(', 'E', ')', 'id']
}

# First sets
first_sets = {
    'E': {'(', 'id'},
    'E\'': {'+', '@'},
    'T': {'(', 'id'},
    'T\'': {'*', '@'},
    'F': {'(', 'id'}
}

# Follow sets
follow_sets = {
    'E': {'$', ')'},
    'E\'': {'$', ')'},
    'T': {'$', ')', '+'},
    'T\'': {'$', ')', '+'},
    'F': {'$', ')', '+', '*'}
}

# Predictive parsing table
parsing_table = {}

for non_terminal in rules.keys():
    for symbol in first_sets[non_terminal]:
        if symbol != '@':
            parsing_table[(non_terminal, symbol)] = rules[non_terminal]
    if '@' in first_sets[non_terminal]:
        for symbol in follow_sets[non_terminal]:
            parsing_table[(non_terminal, symbol)] = ['@']

# Print the parsing table
print('Predictive parsing table:')
for key in parsing_table.keys():
    print(key[0], '\t', key[1], '\t', parsing_table[key])
