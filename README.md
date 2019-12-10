## Exercise: Partition (10 Points)

The objective of this project is to learn about the partition operator as is used in the
pivot action of the quicksort alogorithm, or used to compute the median of an unsorted
container of data.

### Getting Started

The first thing you will need to do is accept the invitation to this 
assignment from GitHub Classroom. You can click 
[here](https://classroom.github.com/a/-sNR3kdr) to accept the 
invitation, and get started.

Be sure that you accept the invitation first and use the URL to your new project when you clone it in CLion. After copying
the URL into the clipboard, in CLion click **VCS -> Checkout from Version Control -> Git**. Paste the URL into the **URL** box of the _Clone Repository_ dialog box and press **Clone**.


### Requirements of this project

This project is based on  `std::partition`, an algorithm, as defined in C++-11. To see more details,
take a look at the documentation on the [CPP Reference](https://en.cppreference.com/w/cpp/algorithm/partition) 
website or the [C++ official](http://www.cplusplus.com/reference/algorithm/partition/) site. 

Our version will take a value rather than a predicate. Therefore, the signature of our function
will be `ForwardIterator partition(ForwardIterator first, ForwardIterator last, Type pivot)`.
The function will partition the container between the iterators `first` and `last` into values
at the lower indices, that are less than or equal to `pivot`, those that are greater thant the
pivot are at the higher indices. For example, the set {6, 3, 2, 4, 1, 5}, if partitioned with the 
pivot value 4, might look something like {2, 3, 4, 1, 6, 5}. Here, everything below index 3 is
less than or equal to 4, and the rest are at higher indices, therefore it is properly partitioned.

Just like the `std::partition` function, or function returns an iterator point to the highest 
index of the values lower than or equal to the pivot value (in the example above, it would return
an iterator pointing to the value 1). Be sure your code handles situations such as an empty 
container (which might also mean that `first` might be equal to `last`).

When you start the project, the code looks like this in `algorithm.h`:

```cpp
namespace edu { namespace vcccd { namespace vc { namespace csv15 {
template <typename UnidirectionalIterator, typename Type>
UnidirectionalIterator partition(UnidirectionalIterator first, UnidirectionalIterator last, const Type &pivot) {
    // Put your partitioning code here

    return first;
}
}}}}
```

Replace `// Put your partitioning code here` with your solution.

### Writing the code for this Project

There is only one requirement for creating the code for this project correctly. 
Fill in all required code for the function `partition` in the namespace `edu::vcccd::vc::csv15` with
the given interface from the reference websites. 

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `Partition | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It could look something like this:

```bash
/tmp/tmp.s3fwukqGrW/cmake-build-debug/../bin/HashTable
5
4
3
2
1
10
9
8
7
6
partitioned

Process finished with exit code 0
```

But in this case, it could be whatever you want to make sure you code works.

Once your code runs and behaves the way you want, Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `Partition Tests | Debug` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
/tmp/tmp.s3fwukqGrW/cmake-build-debug/../bin/HashTable_GTest
Running main() from gtest_main.cc
[==========] Running 6 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 6 tests from PartitionFixture
[ RUN      ] PartitionFixture.TestReverseOrderedVector
[       OK ] PartitionFixture.TestReverseOrderedVector (0 ms)
[ RUN      ] PartitionFixture.TestForwardOrderedVector
[       OK ] PartitionFixture.TestForwardOrderedVector (0 ms)
[ RUN      ] PartitionFixture.TestEmptyVector
[       OK ] PartitionFixture.TestEmptyVector (0 ms)
[ RUN      ] PartitionFixture.TestPivotLower
[       OK ] PartitionFixture.TestPivotLower (0 ms)
[ RUN      ] PartitionFixture.TestPivotHigher
[       OK ] PartitionFixture.TestPivotHigher (0 ms)
[ RUN      ] PartitionFixture.TestPivotNotInContainer
[       OK ] PartitionFixture.TestPivotNotInContainer (0 ms)

Your unit test score is 10 out of 10
The assignment is worth a total of 10 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 6 tests from PartitionFixture (1 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 6 tests.

Process finished with exit code 0
```

You should also see your score for this assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `algorithm.h`, and our changes/additions to `list.h`.
Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked,
but committing will take longer. Put a message in `Commit Message`
and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name,
then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

### Turning in and Grading your code

Go back to LazyGrader and login again, if needed. Press the _Build_ button next to
**EX06-Partition** for this course. This will send a command to Jenkins to download your code
from GitHub and test it. If all goes well and all the tests pass, the ball next to the _Build_
will turn blue. If some of the tests don't pass the ball will be yellow. If the ball is grey,
that means you have not run the tests before and your project is not ready for grading.

Once the Jenkins status is blue or yellow, press the _Grade_ button for **EX06-Partition**.
This will read the results from Jenkins and send your grade to Canvas. Once the notification in 
LazyGrader says the grade has been posted, you should see your grade on Canvas.

That's it, once you've submitted your grade, you are done. I will add points later, after I 
inspect your code. For example, most projects will be out of a total of 25 points, but after 
pressing the _Grade_ button, Canvas will show 20 points. I will add up to 5 points after I have
looked at your code and am convinced it is original.
