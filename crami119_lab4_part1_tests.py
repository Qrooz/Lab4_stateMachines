tests = [ 
    {   #press nothing, 
        'description': 'PINA: 0x00 => PORTB: 0x01',
        'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}],
        'expected': [('PORTB',0x01)],
    },
    {
        'description': 'PINA: 0x01 => PORTB: 0x02',
        'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}],
        'expected': [('PORTB',0x02)],
    },
    {
        'description': 'PINA: 0x01 => PORTB: 0x02',
        'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}],
        'expected': [('PORTB',0x02)],
    },
    {
        'description': 'PINA: 0x00 => PORTB: 0x02',
        'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 1}],
        'expected': [('PORTB',0x02)],
    },
    {
        'description': 'PINA: 0x01 => PORTB: 0x01',
        'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 1}],
        'expected': [('PORTB',0x01)],
    },
    ]
watch = ['state', 'PORTB']
