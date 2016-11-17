/**
 * @file TestObject.java
 * @author yinliang(yinliang@jd.com)
 * @date 2016/11/16 14:28:32
 * @brief 
 *  
 **/







public class TestObject {
    public String name;

    public String pwd;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPwd() {
        return pwd;
    }

    public void setPwd(String pwd) {
        this.pwd = pwd;
    }

    public void callback(String content) {
        System.out.println("%%%call back ok*** cotnent is: " + content);
        System.out.println("name is: " + name);
        System.out.println("pwd is: " + pwd);
    }

}













/* vim: set ts=4 sw=4 sts=4 tw=100 */
