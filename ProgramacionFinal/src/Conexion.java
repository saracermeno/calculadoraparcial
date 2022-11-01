import java.sql.*;
import java.io.FileWriter;

public class Conexion {

    String ip = "localhost";
    String p = "5432";
    String bd = "javadb";
    String basededatos = "jdbc:postgresql://"+ip+":"+p+"/"+bd;
    Connection conexion  = null;

    public void agregarProducto (String nombreProducto, String codigoProducto) {
        try {
            Class.forName("org.postgresql.Driver");
            conexion = DriverManager.getConnection(basededatos, "postgres", "secret");

            Statement s = conexion.createStatement();

            PreparedStatement statement = conexion.prepareStatement("insert into productos values (?, ?)");
            statement.setString(1, nombreProducto);
            statement.setString(2, codigoProducto);
            statement.executeQuery();

            conexion.close();
        }catch (Exception e){
            System.out.println(e.toString());
        }
    }

    public void exportarTXT () {
        try {
            FileWriter archivo = new FileWriter("C:/Users/Public/resultado.txt");

            Class.forName("org.postgresql.Driver");
            conexion = DriverManager.getConnection(basededatos, "postgres", "secret");

            Statement s = conexion.createStatement();

            ResultSet rs = s.executeQuery ("select * from productos");
            int i=0;
            // Se recorre el ResultSet, mostrando por pantalla los resultados.
            while (rs.next())
            {
                archivo.write(rs.getString(1) + " " + rs.getString(2) + "\n");
                i++;
            }
            archivo.close();

            // Se cierra la conexión con la base de datos.
            conexion.close();
        }catch (Exception e) {
            System.out.println("Hubo algun error al guardar");
            System.out.println(e.toString());
        }
    }
}
