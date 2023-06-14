from logging import lastResort
import math
import numpy as np

phi = (math.sqrt(5)-1)/2
#print(f"phi=%f" % phi)
d = math.sqrt(math.pow(0,2) +math.pow(phi,2) +math.pow(math.pow(0,2),2))
'''
(0,±φ,±1/φ)
(±1/φ,0,±φ)
(±φ,±1/φ,0)
(±1,±1,±1)
'''
b = 1
a = b / phi
vertices = [
    [a,a,a		],
    [a+b,0,b	],
    [a,-a,a		],
    [0,-b,a+b	],
    [0,b,a+b	],
    [a+b,0,-b	],
    [a,a,-a		],
    [b,a+b,0	],
    [-b,a+b,0	],
    [-a,a,-a	],
    [0,b,-a-b	],
    [a,-a,-a	],
    [b,-a-b,0	],
    [-b,-a-b,0	],
    [-a-b,0,b	],
    [-a,a,a		],
    [-a,-a,-a	],
    [0,-b,-a-b	],
    [-a,-a,a	],
    [-a-b,0,-b	],
]


face_indices = [
    (19,16,13),
    (19,13,14),
    (14,13,18),

    (18,13,12),
    (3,18,12),
    (3,12,2),

    (4,3,2),
    (4,2,1),
    (4,1,0),

    (9,19,14),
    (9,14,15),
    (9,15,8),

    (14,18,3),
    (14,3,15),
    (15,3,4),

    (8,15,4),
    (8,4,0),
    (8,0,7),

    (7,0,1),
    (7,1,5),
    (7,5,6),

    (5,1,2),
    (5,2,12),
    (5,12,11),

    (8,10,9),
    (8,7,10),
    (7,6,10),

    (10,6,5),
    (10,5,17),
    (17,5,11),

    (17,11,12),
    (17,12,13),
    (17,13,16),

    (9,10,17),
    (9,17,19),
    (19,17,16)
]

for vertex in vertices:
    print(f"{vertex[0]:.4f}, {vertex[1]:.4f}, {vertex[2]:.4f},")
#求点的模
def distance(p):
    x=p[0]
    y=p[1]
    z=p[2]
    return math.sqrt(pow(x,2) + pow(y,2) + pow(z,2))

normals = []
#归一化缩放
max = -1
for vertex in vertices:
    _r = distance(vertex)
    if(_r > max):
        max = _r

for vertex_index in range(len(vertices)):
    vertex = vertices[vertex_index]
    #print(f"DEBUG {vertex[0]}")
    vertex[0]  = vertex[0] / max
    vertex[1]  = vertex[1] / max
    vertex[2]  = vertex[2] / max


print("float vertices[] = {")
#用于统一化所有的法向量
last_normal = []
last_index = -1
for face_index in range(len(face_indices)):
    face = face_indices[face_index]
    #一个面由三个三角形构成，这三个三角形应该共用一个法向量，所以可以通过取整快速略去一些法向量的计算
    #if(int(face_index /3) != last_index):
#
    #    #取点计算两个向量
    #    v1 = np.array(vertices[face[0]])
    #    v2 = np.array(vertices[face[1]])
    #    v3 = np.array(vertices[face[2]])
#
    #    #计算叉乘
    #    normal = np.cross(v2 - v1, v3 - v1)
    #    normalized_normal = normal / np.linalg.norm(normal)
    #    normals.append(normalized_normal)
    #    last_normal = normal
    #    last_index = int(face_index / 3)
    #else:
    #    normal = last_normal
    v1 = np.array(vertices[face[0]])
    v2 = np.array(vertices[face[1]])
    v3 = np.array(vertices[face[2]])
    #计算叉乘
    normal = np.cross(v2 - v1, v3 - v1)
    normalized_normal = normal / np.linalg.norm(normal)
    normals.append(normalized_normal)
    #last_normal = normal
    #last_index = int(face_index / 3)
    for vertex_index in face:
        vertex = vertices[vertex_index]
        print(f"\t{vertex[0]:.2f}f, {vertex[1]:.2f}f, {vertex[2]:.2f}f,\t{normal[0]:.2f}, {normal[1]:.2f}f, {normal[2]:.2f}f,")

print("};")