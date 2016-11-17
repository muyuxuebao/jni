/**
 * @file Test.java
 * @author yinliang(yinliang@jd.com)
 * @date 2016/11/16 14:27:47
 * @brief 
 *  
 **/


public class Test {
    public Test() {

    }

    public String getMessage(){
        return "test ok";
    }

    public TestObject getObject() {
        System.out.println("invoke getObject ok***");
        TestObject to = new TestObject();
        to.setName("name");
        to.setPwd("pwd");
        return to;
    }

    public void test() {
        System.out.println("%%% invoke test ok***");
    }
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
