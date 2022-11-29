

typedef class Activity2
{
    public:
    	
    char Id[5];
    float duracion;
    int Est;
    int Lst;
    int Eet;
    int Let;
    struct Activity2 *Sucesores[100];
    struct Activity2 *Predecesores[100];
}actividades2;

int na2,critico2;
actividades2 *List[100],*check,*check2, *actividad;

void ObtenerActividades2();
void RecorridoAdelante2();
void RecorridoAtras2();
void RutaCritica2();

int VerificarActividad2(char id[5], int i)
{
    for(int j = 0; j < i; j++)
    {
        if(strcmp(List[j]->Id,id) == 0)
            check=List[j];
   }
   return NULL;
}

int ObtenerIndice2(actividades2 *aux, int i)
{
	for(int j = 0; j < i; j++)
    {
        if(aux->Id==List[j]->Id)
      	    return j;
    }
   return 0;
}

int EstablecerSucesores2(actividades2 *actividad)
{
   int k=0;
   while (actividad->Sucesores[k]!= NULL){
      k++;
   }
   return k;
}


void ObtenerActividades2()
{
    do {
        
        cout<<"\n Introduzca el numero de actividades: ";
        cin>>na2;
        if(na2 < 2 )
            cout<<"\n El numero de actividades debe ser mayor o igual a 2 \n\n";
    } while(na2 < 2);

   for(int i = 0; i < na2; i++)
   {
       
	   int toptimista, tprobable, tpesimista;
	   int promedio;
	   
	   actividad = new (class Activity2);
       actividad->Predecesores[0]=NULL;
       actividad->Sucesores[0]=NULL;
       cout<<"\n\tACTIVIDAD "<<(i+1)<<"\n";
       cout<<"\tID\t: ";
       cin>>actividad->Id;
       cout<<"\tTiempo optimista: ";
       cin>>toptimista;
       cout<<"\tTiempo probable: ";
       cin>>tprobable;
       cout<<"\tTiempo pesimista: ";
       cin>>tpesimista;
       promedio= (4*tprobable + toptimista + tpesimista)/6;
       cout<<"\t  Duracion: " << promedio << " Semanas\n";
       actividad->duracion = promedio;
       int np; 
       cout<<"\tNumero de Predecesores : ";
       cin>>np;
       List[i] = actividad;
       if(np != 0) {
           char id[5];
           for(int j = 0; j < np; j++)
           {
               cout<<"\t#"<<(j+1)<<" ID de Predecesor\t: ";
               cin>>id;
               actividad->Predecesores[j] = new (class Activity2);
               actividades2 *aux;
               aux =new (class Activity2);
               int resultados;
               VerificarActividad(id, i);
               if(check != NULL) {
                   actividad->Predecesores[j] = check;
                   resultados = ObtenerIndice(check, i);
                   int k = EstablecerSucesores(List[resultados]);
                   List[resultados]->Sucesores[k] = actividad;
                } else {
                    cout<<"\n Hubo algun error, verifica y vuelve intentalo. \n\n";
                    j--;
                }
            }
       } else {
           actividad->Predecesores[0]=NULL;
       }

    }
}

void RecorridoAdelante2()
{
    for(int i = 0; i < na2; i++)
    {
        if(List[i]->Predecesores[0]==NULL) {
            List[i]->Est=0;
            List[i]->Eet=List[i]->duracion;
        } else {
            int k=0;
            List[i]->Est=0;
            while (List[i]->Predecesores[k]!=NULL) {
                if(List[i]->Est < List[i]->Predecesores[k]->Eet)
                    List[i]->Est = List[i]->Predecesores[k]->Eet;
                //cout<<List[i]->Est<<" "<<List[i]->Predecesores[k]->Eet<<endl;
                k++;
            }
            List[i]->Eet = List[i]->Est + List[i]->duracion;
        }
    }
}

void RecorridoAtras2()
{
    int i;
    int max=List[0]->Eet;
    for(i=1;i<na2;i++)
    {
        if(List[i]->Eet>max)
            max=List[i]->Eet;
    }
    critico2=max;
    int k=na2-1;
    for(int i=k; i>=0; i--)
    {
        if(List[i]->Sucesores[0]!=NULL) {
            int k=0;
            List[i]->Let=List[i]->Sucesores[0]->Lst;
            while (List[i]->Sucesores[k]!=NULL) {
                if(List[i]->Let > List[i]->Sucesores[k]->Lst)
                    List[i]->Let = List[i]->Sucesores[k]->Lst;
                k++;
            }
            List[i]->Lst = List[i]->Let-List[i]->duracion;
        } else {
                List[i]->Let=max;
         List[i]->Lst=max-List[i]->duracion;
      }
   }
}

void RutaCritica2()
{
    for(int i=0; i<na2;i++)
    
    {
        cout<<"\n\n\tNodo "<<i<<" = "<<List[i]->Id;
        cout<<"\n\tDuracion = "<<List[i]->duracion<< " Semanas";
        cout<<"\n\tES = "<<List[i]->Est;
        cout<<"\n\tEF = "<<List[i]->Eet;
        cout<<"\n\tLS = "<<List[i]->Lst;
        cout<<"\n\tLF = "<<List[i]->Let;
        cout<<"\n\tHol = "<<(List[i]->Let)-(List[i]->Eet);
    }
    cout<<"\n\n\tActividades de ruta Critica: "<<endl;
    cout<<endl;

    for(int i=0;i<na2;i++)
    {
        if((List[i]->Eet - List[i]->Let) == 0 && (List[i]->Est - List[i]->Lst)== 0)
            cout<<" - "<<List[i]->Id;
    }
    cout<<"\n\n\tDuracion Total: "<<critico2 << " Semanas";
    cout<<endl;
    cout<<endl;
}
