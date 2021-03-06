#Autor: Diaz Ortiz Brandon Aldair y García Cardenas Ángel Alberto
#Tipos de nodo:
# Raiz
# Pregunta
# Respuesta
# caso
# Operador
class Nodo:
    def __init__(self, datos):
        self.id_padre = int(datos[0])
        self.id_nodo = int(datos[1])
        self.tipo_nodo= datos[2]
        self.valor = datos[3]
        self.parametro = ''
        self.operador= ''
        self.estatus = 0
        self.hijos = None

raiz = Nodo

def descomponer_caso(caso):
    if ">" in caso and ">=" not in caso:
        operador1=caso.find(">")
        resultado=[caso[:operador1],">",caso[operador1+1:]]
        return resultado
    elif "<" in caso and "<=" not in caso:
        operador2=caso.find("<")
        resultado=[caso[:operador2],"<",caso[operador2+1:]]
        return resultado
    elif ">=" in caso:
        operador4=caso.find(">=")
        resultado=[caso[:operador4],">=",caso[operador4+2:]]
        return resultado
    elif "<=" in caso:
        operador5=caso.find("<=")
        resultado=[caso[:operador5],"<=",caso[operador5+2:]]
        return resultado
    elif "=" in caso:
        operador3=caso.find("=")
        resultado=[caso[:operador3],"=",caso[operador3+1:]]
        return resultado

def insertar_nodos(padre,lineas):
    lista_hijos= []
    lista_filtrada=list(filter(lambda x:x[0]==str(padre.id_nodo),lineas))
    #print(lista_filtrada)
    for hijo in lista_filtrada:
        nodo_hijo= Nodo(hijo)
        if (nodo_hijo.tipo_nodo=="caso"):
            valores= descomponer_caso(nodo_hijo.valor)
            nodo_hijo.parametro= valores[0]
            nodo_hijo.operador=valores[1]
            nodo_hijo.valor=valores[2]
            nodo_hijo.tipo_nodo="operador"
        lista_hijos.append(nodo_hijo)
    padre.hijos = lista_hijos
    #print(padre.hijos)
    lista =list(filter(lambda x:x[0]!=padre.id_nodo,lineas))
    #print(lista)
    if lista!=[]:
        for nodo in lista_hijos:
            insertar_nodos(nodo, lista)

def imprimir_nodo(nodo):
    if (nodo.tipo_nodo=="operador"):
        print(f'Nodo {nodo.id_nodo}: Tipo  {nodo.tipo_nodo},Variable: {nodo.parametro},Operador: {nodo.operador}, Valor = {nodo.valor} ')
    else :
        print(f'Nodo {nodo.id_nodo}: Tipo  {nodo.tipo_nodo}, Valor = {nodo.valor} ')
    if nodo.hijos != None:
        for nodo_hijo in nodo.hijos:
            imprimir_nodo(nodo_hijo)

def crear_arbol():
    with open('./conocimiento.txt', encoding='utf-8') as conocimiento:
        renglones= conocimiento.readlines()
        reglas = []
        #print(reglas)
        for linea in renglones:
            regla=linea.replace('\n','')
            regla=regla.split(',')
            reglas.append(regla)
        raiz = Nodo(reglas[0])
        reglas.pop(0)
        insertar_nodos(raiz,reglas)

        #imprimir_nodo(raiz)
        print("\nSe cargo el conocimiento correctamente en el arbol\n")
    return raiz

def evaluar_nodo(nodo,variables):
    nodo.estatus=0
    if nodo.tipo_nodo=="pregunta":
        if nodo.hijos != None:
            for hijo in nodo.hijos:
                if variables.get(hijo.parametro)==None:
                    valor_usr = float(input(nodo.valor+" "))
                    nueva_variable = {hijo.parametro: valor_usr}
                    variables.update(nueva_variable)
                    condicion = float(hijo.valor)
                else: 
                    condicion = float(hijo.valor)
                    valor_usr= variables.get(hijo.parametro)
                if hijo.operador == ">":
                    if valor_usr > condicion:
                        hijo.estatus = 1
                        nodo.estatus +=1 
                if hijo.operador == "<":
                    if valor_usr < condicion:
                        hijo.estatus = 1
                        nodo.estatus +=1 
                if hijo.operador == "=":
                    if valor_usr == condicion:
                        hijo.estatus = 1
                        nodo.estatus +=1 
                if hijo.operador == ">=":
                    if valor_usr >= condicion:
                        hijo.estatus = 1
                        nodo.estatus +=1 
                if hijo.operador == "<=":
                    if valor_usr <= condicion:
                        hijo.estatus = 1
                        nodo.estatus +=1 
        return variables    
    if nodo.tipo_nodo=="respuesta":
        for hijo in nodo.hijos:
            if hijo.estatus >= 1:
                nodo.estatus += 1
                
    if nodo.tipo_nodo=="raiz":
        for hijo in nodo.hijos:
            if hijo.estatus >= 1:
                nodo.estatus += 1

        if nodo.estatus > 1:
            respuestas = 0
            for hijo in nodo.hijos:
                if hijo.estatus > respuestas:
                    respuesta = hijo.valor
                    respuestas = hijo.estatus
            print(f'{nodo.valor} \n La repuesta es {respuesta}')

        elif nodo.estatus == 1:
            for hijo in nodo.hijos:
                if hijo.estatus==1:
                    respuesta = hijo.valor
                    break
            print(f'{nodo.valor}\nLa repuesta es {respuesta}')
        elif nodo.estatus == 0:
            print(f'{nodo.valor}\nNo hay ninguna respuesta optima')

def recorrer_arbol(nodo,tipos_nodo,lista_raiz,lista_preguntas,lista_respuestas,lista_casos,lista_operadores):
    if nodo.hijos != None:
        for nodo_hijo in nodo.hijos:
            if nodo_hijo.tipo_nodo == "pregunta":
                lista_preguntas.append(nodo_hijo)
                nuevo_elemento = {"Preguntas": lista_preguntas}
                tipos_nodo.update(nuevo_elemento)
                recorrer_arbol(nodo_hijo,tipos_nodo,lista_raiz,lista_preguntas,lista_respuestas,lista_casos,lista_operadores)
            if nodo_hijo.tipo_nodo == "respuesta":
                lista_respuestas.append(nodo_hijo)
                nuevo_elemento = {"Respuestas": lista_respuestas}
                tipos_nodo.update(nuevo_elemento)
                recorrer_arbol(nodo_hijo,tipos_nodo,lista_raiz,lista_preguntas,lista_respuestas,lista_casos,lista_operadores)
            if nodo_hijo.tipo_nodo == "operador":
                lista_casos.append(nodo_hijo)
                nuevo_elemento = {"Operador": lista_operadores}
                tipos_nodo.update(nuevo_elemento)
                recorrer_arbol(nodo_hijo,tipos_nodo,lista_raiz,lista_preguntas,lista_respuestas,lista_casos,lista_operadores)
            if nodo_hijo.tipo_nodo == "caso":
                lista_operadores.append(nodo_hijo)
                nuevo_elemento = {"Casos": lista_casos}
                tipos_nodo.update(nuevo_elemento)
                recorrer_arbol(nodo_hijo,tipos_nodo,lista_raiz,lista_preguntas,lista_respuestas,lista_casos,lista_operadores)
    return tipos_nodo

def diagnostico(tipos_nodo):
    #ista_raiz=tipos_nodo.get("Raiz")
    #lista_casos=tipos_nodo.get("Casos")
    lista_preguntas=tipos_nodo.get("Preguntas")
    lista_respuestas=tipos_nodo.get("Respuestas")
    variables={}
    for nodo in lista_preguntas:
        evaluar_nodo(nodo,variables)
    for nodo in lista_respuestas:
        evaluar_nodo(nodo,variables)
    
    evaluar_nodo(raiz,variables)


if __name__ == "__main__":
    
    while True:
        try:
            menu=int(input("Menu \n1. Cargar conocimiento \n2. Ejecutar diagnostico \n3. Salir\n"))
            if menu==1:
                raiz=crear_arbol()
            elif menu==2:
                try:
                    tipos_nodo={}
                    lista_raiz=[]
                    lista_preguntas=[]
                    lista_respuestas=[]
                    lista_casos=[]
                    lista_operadores=[]
                    tipos_nodos=recorrer_arbol(raiz,tipos_nodo,lista_raiz,lista_preguntas,lista_respuestas,lista_casos,lista_operadores)
                    diagnostico(tipos_nodos)
                except AttributeError:
                    print("No se cargo el conocimiento")
            elif menu==3:
                quit()
            else:
                print("Se esperan los numeros 1, 2 o 3 como respuesta")        
        except ValueError:
            print("Se esperan los numeros 1, 2 o 3 como respuesta")