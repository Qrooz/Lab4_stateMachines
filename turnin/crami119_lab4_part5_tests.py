tests = [ 
    {
        'description': 'PINA: 0x03 => PORTB: 0x00',
        'steps': [
            {'inputs': [('PINA', 0x03)], 'iterations': 1},
        ],
        'expected': [('PORTB',0x00)],
    },
    {
        'description': 'PINA: 3,4,0,1,2,0,1,0 => PORTB: 0x01',
        'steps': [
            {'inputs': [('PINA', 0x03)], 'iterations': 1},
            {'inputs': [('PINA', 0x04)], 'iterations': 1},
            {'inputs': [('PINA', 0x00)], 'iterations': 1},
            {'inputs': [('PINA', 0x01)], 'iterations': 1},
            {'inputs': [('PINA', 0x00)], 'iterations': 1},
            {'inputs': [('PINA', 0x02)], 'iterations': 1},
            {'inputs': [('PINA', 0x00)], 'iterations': 1},
            {'inputs': [('PINA', 0x01)], 'iterations': 1},
        ],
        'expected': [('PORTB',0x01)],
    },
    {
        'description': 'PINA: 0x80 => PORTB: 0x00',
        'steps': [
            {'inputs': [('PINA', 0x80)], 'iterations': 1},
        ],
        'expected': [('PORTB',0x00)],
    },
    ]
