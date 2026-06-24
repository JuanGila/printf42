class MiClaseDePrueba:
    """Representa una prueba"""

    def __init__(self, atributo_clase: int):
        self.atributo_clase = atributo_clase
    
    def __str__(self): return f"{self.atributo_clase}"
    # esto es lo que hable con javiesan sobre geters y seters en .py
    def __setattr__(self, name, value): self.__dict__[name] = value

