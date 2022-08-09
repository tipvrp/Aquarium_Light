// ignore_for_file: avoid_print

import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) =>
      const MaterialApp(title: 'MaterialApp', home: MyHomePage());
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key}) : super(key: key);

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

double value1 = 50;

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) => Scaffold(
      appBar: AppBar(
        title: const Text('Plakalung'),
      ),
      body: Column(mainAxisAlignment: MainAxisAlignment.spaceAround, children: [
        Slider(
          value: value1,
          max: 100,
          onChanged: (value) => setState(() {
            value1 = value;
            print(value1);
          }),
        ),
        Text(value1.round().toString())
      ]));
}
