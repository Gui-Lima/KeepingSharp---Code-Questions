public class Matrix {

    @SuppressWarnings("unchecked")
    private static <T extends Throwable> void throwException(Throwable exception, Object dummy) throws T
    {
        throw (T) exception;
    }

    public static void throwException(Throwable exception)
    {
        Matrix.<RuntimeException>throwException(exception, null);
    }

    public static void enter(){
        throwException(new Neo());
    }
}
