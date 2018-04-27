int eGen_baja(eGenerica listado[] ,int limite, int id)
{
    int id;
    int posicion;
    char confirmacion;

    eGen_mostrarListado(listado, limite);

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo(TITULO_BAJA);

    eGen_mostrarListado(listado, limite);

    id = pedirInt("\n\nIngrese el ID del generica a dar de baja: ");

    do
    {
        posicion = eGen_buscarPorId(listado, limite, id);
        if(posicion != -1)
        {
            if(listadoAlumnos[posicion].estado == 0)
            {
                imprimirEnPantalla("\nEl ID ya se encontraba dado de baja");
            }
            else
            {
                mostrarAlumno(listadoAlumnos[posicion]);

                confirmacion = pedirConfirmacion("Confirma que desea dar de baja dicho alumno?");

                if(confirmacion == 'S')
                {
                    listadoAlumnos[posicion].estado = 0;
                    imprimirEnPantalla("\nEl ID se dio de baja.");
                }
                else
                {
                    imprimirEnPantalla("\nSe cancelà la gestiàn.");
                }
            }
        }
        else
        {
            imprimirEnPantalla("\nEl ID ingresado por par metro no existe.");
        }

    }
    while(posicion < 0);

    ejecutarEnConsola(HACER_PAUSA);
}
