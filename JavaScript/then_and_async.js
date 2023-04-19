function main() {
  console.log("main: begin");
  _createData1()
    .then((data1) => {
      console.log("data1: " + data1.data);
      return _createData2();
    })
    .then((data2) => {
      console.log("data2: " + data2.data);
      return _createData3();
    })
    .then((data3) => {
      console.log("data3: " + data3.data);
      console.log("main: end");
    })
    .catch((error) => {
      console.error("Error: " + error);
    });
}

function loadFromDisk() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(42);
    }, 2000);
  });
}

function fetchNetworkData(id) {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("network data with id: " + id);
    }, 2000);
  });
}

class CreatedData {
  constructor(data) {
    this.data = data;
  }

  static empty() {
    return new CreatedData("empty");
  }
}

function _createData1() {
  return loadFromDisk()
    .then((id) => {
      return fetchNetworkData(id);
    })
    .then((data) => {
      return new CreatedData(data);
    });
}

async function _createData2() {
  const id = await loadFromDisk();
  const data = await fetchNetworkData(id);
  return new CreatedData(data);
}

async function _createData3() {
  try {
    const id = await loadFromDisk();
    const data = await fetchNetworkData(id);
    return new CreatedData(data);
  } catch (e) {
    console.error("Error: " + e);
    return CreatedData.empty();
  } finally {
    console.log("All done!");
  }
}

main();
