tests = [ 
    {
        'description': 'PINA: 0x00 => PORTC: 0x07',
        'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}],
        'expected': [('PORTC',0x07)],
    },
    {
        'description': 'PINA: 0x01 => PORTC: 0x08',
        'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}],
        'expected': [('PORTC',0x08)],
    },
    {
        'description': 'PINA: 0x01 => PORTC: 0x08',
        'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}],
        'expected': [('PORTC',0x08)],
    },
    {
        'description': 'PINA: 0x00 => PORTC: 0x08',
        'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}],
        'expected': [('PORTC',0x08)],
    },
    {
        'description': 'PINA: 0x02 => PORTC: 0x07',
        'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 1}],
        'expected': [('PORTC',0x07)],
    },
    {
        'description': 'Count Up to 9PINA: 0x01 => PORTC: 0x09',
        'steps': [
            {'inputs': [('PINA', 0x01)], 'iterations': 1},
            {'inputs': [('PINA', 0x00)], 'iterations': 1},
            {'inputs': [('PINA', 0x01)], 'iterations': 1},
            {'inputs': [('PINA', 0x00)], 'iterations': 1},
        ],
        'expected': [('PORTC',0x09)],
    },
    ]
#watch = ['B_State', 'PORTC']
