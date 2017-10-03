import tensorflow as tf

node1 = tf.constant(3.0, dtype=tf.float32)
node2 = tf.constant(4.0) #implicitly defined as a float

print(node1, node2)

sess = tf.Session()
print(sess.run([node1, node2]))

node3 = tf.add(node1, node2)
print("node3", node3)
print("sess.run(node3)", sess.run(node3))

##

a = tf.placeholder(tf.float32)
b = tf.placeholder(tf.float32)
adder_node = a + b

print(sess.run(adder_node, {a: 3, b: 4}))
print(sess.run(adder_node, {b: [3,2], a: [4,5]}))


##

W = tf.Variable([.3], dtype=tf.float32)
b = tf.Variable([-.3], dtype=tf.float32)
x = tf.placeholder(tf.float32)

linear_model = W * x + b

init = tf.global_variables_initializer()
sess.run(init)

print(sess.run(linear_model, {x: [1,2,3,4]} ))

y = tf.placeholder(tf.float32)
squared_deltas = tf.square(linear_model - y)
loss = tf.reduce_sum(squared_deltas)
print(sess.run(loss, {x: [1,2,3,4], y: [0,-1,-2,-3]}))

fixW = tf.assign(W, [-1])
fixb = tf.assign(b, [1])
sess.run([fixW, fixb])

print(sess.run(loss, {x: [1,2,3,4], y: [0,-1,-2,-3]}))


optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)