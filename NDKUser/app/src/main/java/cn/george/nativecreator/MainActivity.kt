package cn.george.nativecreator

/**
 * Created By George
 * Description:kotlin实现JNI
 */
class MainActivity {
    companion object{
        init {
            System.loadLibrary("native-lib")
        }
    }
    external fun stringFromJNI( top:String, bottom:String ,brow: String , eyes:String ):String
}