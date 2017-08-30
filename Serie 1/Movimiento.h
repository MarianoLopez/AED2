/*Archivo cabecera propio*/
struct movimiento{
	int nroCuenta; /*4bytes*/
	int documento;/*4bytes*/
	float importe;/*4bytes*/
	int codMovimiento; /*4bytes*/ /*1.Depósito 2.Extracción*/
};/*total: 16bytes.*/

typedef struct movimiento Movimiento;/*definir Movimiento como nuevo tipo de datos, a partir de la estructura movimiento*/
void imprimirMovimiento(Movimiento *movimiento);/*prototipo*/

void imprimirMovimiento(Movimiento *movimiento){
	printf("\tnroCuenta: %d\n\tdocumento: %d\n\timporte: %.2f\n\tcodMovimiento: %d\n\n",
		movimiento->nroCuenta,
		movimiento->documento,
		movimiento->importe,
		movimiento->codMovimiento
	);
}
