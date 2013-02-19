/**
 * image scale with FreeImage library.
 * 
 * @author Yang XuePing
 */
public class ImageScale {
    public native int imageScale(String src, String desc, int newWidth);

    static {
        System.loadLibrary("ImageScale");
    }

    public static void main(String[] args) {
        new ImageScale().imageScale("/home/zcyangxp/develop/test.jpg",
                "/home/zcyangxp/develop/test001.jpg", 300);
    }
}
